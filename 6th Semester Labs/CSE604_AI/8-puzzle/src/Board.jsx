import React, { useEffect, useState } from "react";
import { Puzzle } from "./8-puzzle";
import "./App.css";
import { isSolvable } from "./solvability";

const GRID_SIZE = 3;

function Board() {
  const [tiles, setTiles] = useState(createInitialTiles([]));
  const [solvable, setSolvable] = useState(false);
  const [solution, setSolution] = useState([]);

  function createInitialTiles(initialTiles) {
    // const initialTiles = [];

    for (let i = 0; i < GRID_SIZE; i++) {
      const row = [];

      for (let j = 0; j < GRID_SIZE; j++) {
        const num = i * GRID_SIZE + j + 1;
        row.push(num === GRID_SIZE * GRID_SIZE ? null : num);
      }

      initialTiles.push(row);
    }

    console.log("ROWS: " + initialTiles);
    return initialTiles;
  }

  function changeState(state) {
    const newTiles = [...tiles];
    for (let i = 0; i < GRID_SIZE; i++) {
      for (let j = 0; j < GRID_SIZE; j++) {
        if (state[i][j] === 0) newTiles[i][j] = null;
        else newTiles[i][j] = state[i][j];
      }
    }
    setTiles(newTiles);
  }

  function moveTile(row, col) {
    const emptyRowCol = findEmptyTile();
    if (!emptyRowCol) return;

    const [emptyRow, emptyCol] = emptyRowCol;
    if (
      (row === emptyRow && Math.abs(col - emptyCol) === 1) ||
      (col === emptyCol && Math.abs(row - emptyRow) === 1)
    ) {
      const newTiles = [...tiles];
      newTiles[emptyRow][emptyCol] = tiles[row][col];
      newTiles[row][col] = null;
      setTiles(newTiles);
    }
  }

  function findEmptyTile() {
    for (let i = 0; i < GRID_SIZE; i++) {
      for (let j = 0; j < GRID_SIZE; j++) {
        if (tiles[i][j] === null) {
          return [i, j];
        }
      }
    }
    return null;
  }

  function shuffleSeq() {
    const defaultRow = [1, 2, 3, 4, 5, 6, 7, 8, null]; // Note: Null should be at the end
    const shuffledRow = defaultRow.sort(() => Math.random() - 0.5);

    const newTiles = [];
    let index = 0;

    for (let i = 0; i < GRID_SIZE; i++) {
      const row = [];
      for (let j = 0; j < GRID_SIZE; j++) {
        row.push(shuffledRow[index++]);
      }
      newTiles.push(row);
    }

    console.log("new: ", newTiles);
    setTiles(newTiles);
  }

  function solve() {
    console.log("Initial: ", tiles);
    const goal = [
      [0, 1, 2],
      [5, 6, 3],
      [4, 7, 8],
    ];

    let solution = [];

    const ret = isSolvable(tiles);
    setSolvable(ret);

    if (ret) {
      // convert tiles to array
      const newTiles = [];
      for (let i = 0; i < GRID_SIZE; i++) {
        const row = [];
        for (let j = 0; j < GRID_SIZE; j++) {
          if (tiles[i][j] === null) row.push(0);
          else row.push(tiles[i][j]);
        }
        newTiles.push(row);
      }

      const puzzle = new Puzzle(newTiles, goal);
      puzzle.findSolution();
      solution = puzzle.print();
    }

    console.log("GOAL: ", solution);
    if (solution === undefined) {
      setSolvable(false);
    }

    setSolution(solution);
  }

  useEffect(() => {
    if (solvable && solution.length > 0) {
      let currentIndex = 0;

      const interval = setInterval(() => {
        if (currentIndex < solution.length) {
          changeState(solution[currentIndex][0]);
          currentIndex++;
        } else {
          clearInterval(interval);
        }
      }, 1000);

      return () => clearInterval(interval);
    }

    
  }, [solvable, solution]);

  return (
    <div className="App">
      <h1>8-Puzzle Game</h1>
      <div className="grid">
        {tiles.map((row, rowIndex) => (
          <div key={rowIndex} className="row">
            {row.map((tile, colIndex) => (
              <div
                key={colIndex}
                className="tile"
                onClick={() => moveTile(rowIndex, colIndex)}
              >
                {tile !== null ? tile : ""}
              </div>
            ))}
          </div>
        ))}
      </div>

      {/*Buttons*/}
      <div className="">
        <button
          onClick={shuffleSeq}
          className="border-2 p-2 rounded-xl m-1 font-medium bg-green-500"
        >
          Shuffle
        </button>
        <button
          onClick={solve}
          className="border-2 p-2 rounded-xl font-medium bg-red-500 "
        >
          Solve{" "}
        </button>
      </div>

      {/* Status */}
      <div
        className={`mt-10 font-bold text-xl ${
          solvable ? "text-green-600" : "text-red-600"
        }`}
      >
        {solvable ? "Solved" : "Not Solvable"}
      </div>
    </div>
  );
}

export default Board;
