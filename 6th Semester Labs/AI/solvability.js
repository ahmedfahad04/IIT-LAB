
function getInvCount(arr)
{
	let inv_count = 0 ;
    const narr = arr.flat()

    console.log("INITIAL ARRAY: ", narr)

    for(let i=0; i<9; i++){
        for(let j=i+1; j<9; j++){
            if(narr[i] > narr[j] && narr[j] != 0){
                inv_count++;
                console.log(narr[i], '>' , narr[j])
            }
        }
    }
	return inv_count;
}
// This function returns true
// if given 8 puzzle is solvable.
function isSolvable(puzzle)
{
	// Count inversions in given 8 puzzle
	let invCount = getInvCount(puzzle);
    console.log("INV COUNT: ", invCount)
	// return true if inversion count is even.
	return (invCount % 2 == 0);
}

// Driver code

// Value 0 is used for empty space
puzzle = [[8, 3, 5], [4, 1, 6], [2, 7, 0]] ;
if(isSolvable(puzzle))
	console.log("Solvable");
else
	console.log("Not Solvable");


