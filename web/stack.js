const stack = [];

const valueInput = document.getElementById("valueInput");

const pushBtn = document.getElementById("pushBtn");
const popBtn = document.getElementById("popBtn");

const stackContainer = document.getElementById("stackContainer");

const topValue = document.getElementById("topValue");
const sizeValue = document.getElementById("sizeValue");

function render() {
    stackContainer.innerHTML = "";

    if (stack.length === 0) {
        stackContainer.innerHTML =
            `<p class="empty-text">NULL</p>`;

        topValue.textContent = "NULL";
        sizeValue.textContent = "0";

        return;
    }

    for (let i = stack.length - 1; i >= 0; i--) {
        const node = document.createElement("div");

        node.className = "stack-node";
        node.textContent = stack[i];

        stackContainer.appendChild(node);
    }

    topValue.textContent = stack[stack.length - 1];
    sizeValue.textContent = stack.length;
}

function pushValue() {
    const value = valueInput.value;

    if (value === "") {
        alert("값을 입력하세요.");
        return;
    }

    stack.push(Number(value));

    valueInput.value = "";

    render();
}

function popValue() {
    if (stack.length === 0) {
        alert("Stack is empty");
        return;
    }

    stack.pop();

    render();
}

pushBtn.addEventListener("click", pushValue);

popBtn.addEventListener("click", popValue);

render();