let array = [];

particlesJS("particles-js", {
    particles: {
        number: { value: 80, density: { enable: true, value_area: 800 } },
        color: { value: [ "#00ff00", "#0000ff" ,"#ffffff"] },    // "#00ff00", "#0000ff" ,
        shape: { type: "star" },
        opacity: { value: 0.5, random: true },
        size: { value: 7.5, random: true },
        move: { enable: true, speed: 2 },
        line_linked: { enable: true, distance: 150, color: "#ffffff", opacity: 0.4, width: 1 }
    },
    interactivity: {
        events: {
            onhover: { enable: true, mode: "repulse" }, // Particles move away on hover
            // onclick: { enable: true, mode: "bubble" } // Particles spawn on click
        }
    },
    retina_detect: true
});




function generateArray() {
    const container = document.getElementById("array-container");
    container.innerHTML = "";
    array = [];

    for (let i = 0; i < 10; i++) {
        let num = Math.floor(Math.random() * 100) + 1;
        array.push(num);
        let numDiv = document.createElement("div");
        numDiv.classList.add("num");
        numDiv.innerText = num;
        container.appendChild(numDiv);
    }
}

function setUserArray() {
    const input = document.getElementById("user-input").value;
    array = input.split(",").map(num => parseInt(num.trim()));

    if (array.some(isNaN)) {
        alert("Invalid input! Enter numbers separated by commas.");
        return;
    }

    const container = document.getElementById("array-container");
    container.innerHTML = "";
    array.forEach(num => {
        let numDiv = document.createElement("div");
        numDiv.classList.add("num");
        numDiv.innerText = num;
        container.appendChild(numDiv);
    });
}

async function startSorting() {
    const method = document.getElementById("sorting-method").value;

    if (method === "bubble") await bubbleSort();
    else if (method === "selection") await selectionSort();
    else if (method === "insertion") await insertionSort();
    else if (method === "merge") await mergeSort(0, array.length - 1);
    else if (method === "quick") await quickSort(0, array.length - 1);
    
}

// Bubble Sort
async function bubbleSort() {
    let elements = document.querySelectorAll(".num");
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = 0; j < array.length - i - 1; j++) {
            elements[j].classList.add("active");
            elements[j + 1].classList.add("active");
            await sleep(300);

            if (array[j] > array[j + 1]) {
                elements[j].classList.remove("active");
                elements[j + 1].classList.remove("active");
                elements[j].classList.add("swap");
                elements[j + 1].classList.add("swap");

                [array[j], array[j + 1]] = [array[j + 1], array[j]];
                elements[j].innerText = array[j];
                elements[j + 1].innerText = array[j + 1];

                await sleep(300);
            }

            elements[j].classList.remove("swap", "active");
            elements[j + 1].classList.remove("swap", "active");
        }
        elements[array.length - i - 1].classList.add("sorted");
    }
}

// Selection Sort
async function selectionSort() {
    let elements = document.querySelectorAll(".num");
    for (let i = 0; i < array.length - 1; i++) {
        let minIndex = i;
        elements[minIndex].classList.add("active");

        for (let j = i + 1; j < array.length; j++) {
            elements[j].classList.add("active");
            await sleep(300);

            if (array[j] < array[minIndex]) {
                elements[minIndex].classList.remove("active");
                minIndex = j;
                elements[minIndex].classList.add("active");
            }

            elements[j].classList.remove("active");
        }

        [array[i], array[minIndex]] = [array[minIndex], array[i]];
        elements[i].innerText = array[i];
        elements[minIndex].innerText = array[minIndex];

        elements[minIndex].classList.remove("active");
        elements[i].classList.add("sorted");
    }
}

// Insertion Sort
async function insertionSort() {
    let elements = document.querySelectorAll(".num");
    for (let i = 1; i < array.length; i++) {
        let key = array[i];
        let j = i - 1;

        while (j >= 0 && array[j] > key) {
            elements[j + 1].innerText = array[j];
            array[j + 1] = array[j];
            j--;
            await sleep(300);
        }
        array[j + 1] = key;
        elements[j + 1].innerText = key;
        elements[j + 1].classList.add("sorted");
    }
}

// Utility Function: Sleep
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// Load a random array on page load
window.onload = generateArray;
