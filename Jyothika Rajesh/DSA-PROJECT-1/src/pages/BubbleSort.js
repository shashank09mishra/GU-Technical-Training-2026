import React, { useState, useEffect } from "react";
import "./SortingVisualizer.css";

const BubbleSort = () => {
  const [array, setArray] = useState([]);
  const [speed, setSpeed] = useState(100);
  const [size, setSize] = useState(20);
  const [isSorting, setIsSorting] = useState(false);
  
  useEffect(() => {
    generateArray();
  }, [size]);

  const generateArray = () => {
    const newArray = Array.from({ length: size }, () => Math.floor(Math.random() * 100));
    setArray(newArray);
  };

  const bubbleSort = async () => {
    setIsSorting(true);
    let arr = [...array];
    let n = arr.length;
    for (let i = 0; i < n - 1; i++) {
      for (let j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
          setArray([...arr]);
          await new Promise((resolve) => setTimeout(resolve, speed));
        }
      }
    }
    setIsSorting(false);
  };

  return (
    <div className="visualizer-container">
      <h1>Bubble Sort Visualization</h1>
      
      <div className="visualizer">
        {array.map((value, index) => (
          <div
            key={index}
            className="bar"
            style={{ height: `${value * 3}px` }}
          ></div>
        ))}
      </div>

      <div className="controls">
        <button onClick={generateArray} disabled={isSorting}>Reset</button>
        <button onClick={bubbleSort} disabled={isSorting}>Bubble Sort</button>
        <label>
          Speed: 
          <input
            type="range"
            min="10"
            max="500"
            value={speed}
            onChange={(e) => setSpeed(Number(e.target.value))}
          />
        </label>
        <label>
          Size: 
          <input
            type="range"
            min="5"
            max="50"
            value={size}
            onChange={(e) => setSize(Number(e.target.value))}
          />
        </label>
      </div>
    </div>
  );
};

export default BubbleSort;
