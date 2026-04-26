const list = [];

const valueInput = document.getElementById("valueInput");

const insertFrontBtn = document.getElementById("insertFrontBtn");
const insertBackBtn = document.getElementById("insertBackBtn");
const removeFrontBtn = document.getElementById("removeFrontBtn");
const removeBackBtn = document.getElementById("removeBackBtn");

const listContainer = document.getElementById("listContainer");

const headValue = document.getElementById("headValue");
const sizeValue = document.getElementById("sizeValue");

function render() {
    listContainer.innerHTML = "";

    if (list.length === 0) {
        listContainer.innerHTML = `<p class="empty-text">NULL</p>`;
        headValue.textContent = "NULL";
        sizeValue.textContent = "0";
        return;
    }

    for (let i = 0; i < list.length; i++) {
        const node = document.createElement("div");
        node.className = "list-node";
        node.textContent = list[i];

        listContainer.appendChild(node);

        const arrow = document.createElement("span");
        arrow.className = "arrow";
        arrow.textContent = "→";

        listContainer.appendChild(arrow);
    }

    const nullNode = document.createElement("span");
    nullNode.className = "null-node";
    nullNode.textContent = "NULL";

    listContainer.appendChild(nullNode);

    headValue.textContent = list[0];
    sizeValue.textContent = list.length;
}

function getValue() {
    return valueInput.value;
}

function insertFront() {
    const value = getValue();

    if (value === "") {
        alert("값을 입력하세요.");
        return;
    }

    list.unshift(Number(value));
    valueInput.value = "";

    render();
}

function insertBack() {
    const value = getValue();

    if (value === "") {
        alert("값을 입력하세요.");
        return;
    }

    list.push(Number(value));
    valueInput.value = "";

    render();
}

function removeFront() {
    if (list.length === 0) {
        alert("List is empty");
        return;
    }

    list.shift();
    render();
}

function removeBack() {
    if (list.length === 0) {
        alert("List is empty");
        return;
    }

    list.pop();
    render();
}

insertFrontBtn.addEventListener("click", insertFront);
insertBackBtn.addEventListener("click", insertBack);
removeFrontBtn.addEventListener("click", removeFront);
removeBackBtn.addEventListener("click", removeBack);

render();