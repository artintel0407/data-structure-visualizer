const queue = [];

const valueInput = document.getElementById("valueInput");

const enqueueBtn = document.getElementById("enqueueBtn");
const dequeueBtn = document.getElementById("dequeueBtn");

const queueContainer = document.getElementById("queueContainer");

const frontValue = document.getElementById("frontValue");
const rearValue = document.getElementById("rearValue");
const sizeValue = document.getElementById("sizeValue");

function render() {
    queueContainer.innerHTML = "";

    if (queue.length === 0) {
        queueContainer.innerHTML = `<p class="empty-text">NULL</p>`;

        frontValue.textContent = "NULL";
        rearValue.textContent = "NULL";
        sizeValue.textContent = "0";

        return;
    }

    for (let i = 0; i < queue.length; i++) {
        const node = document.createElement("div");

        node.className = "queue-node";
        node.textContent = queue[i];

        queueContainer.appendChild(node);
    }

    frontValue.textContent = queue[0];
    rearValue.textContent = queue[queue.length - 1];
    sizeValue.textContent = queue.length;
}

function enqueueValue() {
    const value = valueInput.value;

    if (value === "") {
        alert("값을 입력하세요.");
        return;
    }

    queue.push(Number(value));

    valueInput.value = "";

    render();
}

function dequeueValue() {
    if (queue.length === 0) {
        alert("Queue is empty");
        return;
    }

    queue.shift();

    render();
}

enqueueBtn.addEventListener("click", enqueueValue);
dequeueBtn.addEventListener("click", dequeueValue);

render();