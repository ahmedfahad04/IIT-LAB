const {isSolvable} = require('./solvability');
// index.js

class Node {
    constructor(state = null, parent = null, action = null) {
        this.state = state;
        this.parent = parent;
        this.action = action;
    }
}

class Frontier {

    constructor() {
        this.frontier = []
    }

    isEmpty() {
        return this.frontier.length === 0;
    }

    size() {
        return this.frontier.length;
    }

    push(node) {
        this.frontier.push(node);
    }

    pop() {
        if (this.isEmpty()) {
            throw new Error("Empty Frontier");
        }

        return this.frontier.pop();
    }

    front() {
        return this.frontier.shift();
    }

    back() {
        return this.frontier.unshift();
    }

    areEqualStates(state1, state2) {
        for (let i = 0; i < state1.length; i++) {
            if (state1[i] !== state2) return false;
        }

        return true;
    }

    containState(state) {

        return this.frontier.some((node) => {
            this.areEqualStates(node.state[0], state[0])
        });
    }

}

// inherit Frontier
class QueueFrontier extends Frontier {
    // inherit
  
    pop() {
      if (this.isEmpty()) {
        throw new Error("Empty Frontier");
      } else {
        const node = this.frontier[0];
        this.frontier = this.frontier.slice(1);
        return node;
      }
    }
}
  
const explored = new Set(); // Class-level property to store explored states as a Set

class Puzzle {

    constructor(start, goal) {
        this.start = [start, this.findIndex(start)];
        this.goal = [goal, this.findIndex(goal)];
        this.solution = null;
        this.countExploredState = 0;
    }

    findIndex(state) {
        for(let i=0; i<state.length; i++) {
            for (let j=0; j<state[i].length; j++)
            {
                if (state[i][j] === 0) {
                    return [i, j];
                }
            }
        }    
    }

    neighbors(state) {
        console.log("STATE: " + JSON.stringify(state));
        
        const [matrix, [row, col]] = state;
        const results = [];

        console.log("initial: " + [row, col])

        if (row > 0) {
            const mat1 = JSON.parse(JSON.stringify(matrix)); // Create a deep copy of the matrix otherwise would create a shallow copy, and modifications to mat1 would also affect the original mat
            mat1[row][col] = mat1[row - 1][col];
            mat1[row - 1][col] = 0;
            results.push(['up', [mat1, [row - 1, col]]]);
        }

        if (col > 0) {
            const mat1 = JSON.parse(JSON.stringify(matrix));
            mat1[row][col] = mat1[row][col - 1];
            mat1[row][col - 1] = 0;
            results.push(['left', [mat1, [row, col - 1]]]);
        }

        if (row < 2) {
            const mat1 = JSON.parse(JSON.stringify(matrix));
            mat1[row][col] = mat1[row + 1][col];
            mat1[row + 1][col] = 0;
            results.push(['down', [mat1, [row + 1, col]]]);
        }

        if (col < 2) {
            const mat1 = JSON.parse(JSON.stringify(matrix));
            mat1[row][col] = mat1[row][col + 1];
            mat1[row][col + 1] = 0;
            results.push(['right', [mat1, [row, col + 1]]]);
        }

        return results; // Add this line to return the array of neighboring states
    }

    print() {
        const solution = this.solution || null;
        console.log("Start State:\n", this.start[0], "\n");
        console.log("Goal State:\n", this.goal[0], "\n");
        console.log("Iteration: ", this.countExploredState)
        console.log("Solution:\n ");

        if (solution) {
            for (let i = 1; i < solution[0].length; i++) {
                const action = solution[0][i];
                const cell = solution[1][i];
                console.log("Goal Reached!!");

                console.log("action: ", action);
                for (const item of cell[0]) {
                    console.log(item);
                }
            }
            return solution[1];
        } else {
            console.log("No solution found.");
        }
    }

    // Method to check if the state has been explored
    // [Inside Set even if two object have same content they will be different
    // as Set compare two element based on memory address. Therefore
    // we used stringify to convert the array to string]
    isStateExplored(state) {
        return explored.has(JSON.stringify(state[0])); // Assuming state[0] is a 2D matrix
    }

    // Method to add a state to the explored set
    addToExplored(state) {
        explored.add(JSON.stringify(state[0]));
    }

    // Method to check if the state is the goal state
    isGoalState(state) {
        return JSON.stringify(state[0]) === JSON.stringify(this.goal[0]);
    }

    // Helper method to get the path from the start node to the current node
    getPath(node) {
        const actions = [];
        const cells = [];
        while (node !== null) {
            actions.unshift(node.action);
            cells.unshift(node.state);
            node = node.parent;
        }
        return [actions, cells];
    }

    doesNotContainState(state) {
        return !explored.has(JSON.stringify(state[0]));
    }

    // Method to find and return the solution
    findSolution() {
        const startNode = new Node(this.start);
        const frontier = new QueueFrontier();
        frontier.push(startNode);

        while (true) {
            if (frontier.isEmpty()) {
                return "No Solution found"
            }

            const node = frontier.pop();
            this.countExploredState += 1; // Increment the count of explored states
            this.addToExplored(node.state);

            if(this.countExploredState > 100000) {
                console.log('No solution found within 10000 levels')
                return "No Solution found";
            }

            if (this.isGoalState(node.state)) {
                this.solution = this.getPath(node);
                return;
            }

            for (const [action, state] of this.neighbors(node.state)) {
                if (!frontier.containState(state) && this.doesNotContainState(state)) {
                    const child = new Node(state, node, action);
                    console.log("ST: " + child.state + " -> " + this.countExploredState);
                    frontier.push(child);
                }
            }
        }
    }


}

// test solvability 
// let checkSolvability = isSolvable([[0, 2, 3], [1, 4, 5], [8, 7, 6]]);
// console.log("Is it Solvable? ", checkSolvability);

// // Example input
// const startState = [[7,2,4], [5,0,6], [8,3,1]];
// const goalState = [[0,1,2], [3,4,5], [6,7,8]];
// // const goalState = [[1,2,3], [4,5,6], [7,8,0]];

// const myPuzzle = new Puzzle(startState, goalState);
// myPuzzle.findSolution();
// myPuzzle.print();
