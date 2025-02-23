import React from "react";
import { Link } from "react-router-dom";
import "./Home.css"; 

const Home = () => {
  return (
    <div className="home-container">
      <h1>Sorting Algorithms</h1>
      <p>Sorting algorithms rearrange elements based on a comparison operation. Here are some common ones:</p>

      <div className="sorting-grid">
        {/* Bubble Sort */}
        <div className="sorting-card">
          <h2>Bubble Sort</h2>
          <img src="/images/bubble_sort.png" alt="Bubble Sort" />
          <Link to="/bubble">
            <button className="btn">Learn More</button>
          </Link>
        </div>

        {/* Selection Sort */}
        <div className="sorting-card">
          <h2>Selection Sort</h2>
          <img src="/images/selection_sort.png" alt="Selection Sort" />
          <Link to="/selection">
            <button className="btn">Learn More</button>
          </Link>
        </div>

        {/* Insertion Sort */}
        <div className="sorting-card">
          <h2>Insertion Sort</h2>
          <img src="/images/insertion_sort.png" alt="Insertion Sort" />
          <Link to="/insertion">
            <button className="btn">Learn More</button>
          </Link>
        </div>

        {/* Merge Sort */}
        <div className="sorting-card">
          <h2>Merge Sort</h2>
          <img src="/images/merge_sort.png" alt="Merge Sort" />
          <Link to="/merge">
            <button className="btn">Learn More</button>
          </Link>
        </div>

        {/* Quick Sort */}
        <div className="sorting-card">
          <h2>Quick Sort</h2>
          <img src="/images/quick_sort.png" alt="Quick Sort" />
          <Link to="/quick">
            <button className="btn">Learn More</button>
          </Link>
        </div>
      </div>
    </div>
  );
};

export default Home;
