const capacity = 8;
const array = new Array(capacity).fill(0);

const indexInput = document.getElementById("indexInput");
const valueInput = document.getElementById("valueInput");

const setBtn = document.getElementById("setBtn");
const insertBtn = document.getElementById("insertBtn");
const eraseBtn = document.getElementById("eraseBtn");

const arrayContainer = document.getElementById("arrayContainer");
const sizeValue = document.getElementById("sizeValue");
const selectedValue = document.getElementById("selectedValue");

function render(activeIndex = -1) {
    arrayContainer.innerHTML = "";

    for (let i = 0; i < capacity; i++) {
        const wrapper = document.createElement("div");
        wrapper.className = "array-cell-wrapper";

        const index = document.createElement("div");
        index.className = "array-index";
        index.textContent = i;

        const cell = document.createElement("div");
        cell.className = "array-cell";
        cell.textContent = array[i];

        if (i === activeIndex) {
            cell.classList.add("active");
        }

        wrapper.appendChild(index);
        wrapper.appendChild(cell);
        arrayContainer.appendChild(wrapper);
    }

    sizeValue.textContent = capacity;
}

function isValidIndex(idx) {
    return idx >= 0 && idx < capacity;
}

function getIndex() {
    return Number(indexInput.value);
}

function getValue() {
    return Number(valueInput.value);
}

function setValue() {
    const idx = getIndex();
    const value = getValue();

    if (!isValidIndex(idx) || valueInput.value === "") {
        alert("index와 value를 올바르게 입력하세요.");
        return;
    }

    array[idx] = value;
    selectedValue.textContent = `array[${idx}] = ${value}`;
    render(idx);
}

function insertValue() {
    const idx = getIndex();
    const value = getValue();

    if (!isValidIndex(idx) || valueInput.value === "") {
        alert("index와 value를 올바르게 입력하세요.");
        return;
    }

    for (let i = capacity - 1; i > idx; i--) {
        array[i] = array[i - 1];
    }

    array[idx] = value;

    selectedValue.textContent = `insert ${value} at ${idx}`;
    render(idx);
}

function eraseValue() {
    const idx = getIndex();

    if (!isValidIndex(idx)) {
        alert("index를 올바르게 입력하세요.");
        return;
    }

    for (let i = idx; i < capacity - 1; i++) {
        array[i] = array[i + 1];
    }

    array[capacity - 1] = 0;

    selectedValue.textContent = `erase index ${idx}`;
    render(idx);
}

setBtn.addEventListener("click", setValue);
insertBtn.addEventListener("click", insertValue);
eraseBtn.addEventListener("click", eraseValue);

render();