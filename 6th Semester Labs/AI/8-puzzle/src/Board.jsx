import React from 'react';

class EightPuzzleGrid extends React.Component {
  constructor(props) {
    super(props);
    // Assuming you have an initial state for the puzzle
    this.state = {
      puzzleGrid: [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
      ],
    };
  }

  render() {
    const { puzzleGrid } = this.state;

    return (
      <div>
        {puzzleGrid.map((row, rowIndex) => (
          <div key={rowIndex} style={{ display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
            {row.map((cellValue, colIndex) => (
              <div key={colIndex} style={{ border: '1px solid black', padding: '10px' }}>
                {cellValue}
              </div>
            ))}
          </div>
        ))}
      </div>
    );
  }
}

export default EightPuzzleGrid;
