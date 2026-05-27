const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");
const entities = new Map();

// --- WebSocket connection --
const socket = new WebSocket("ws://localhost:9001");

socket.onopen = () => {
    console.log("Connected to server");
};

socket.onmessage = (event) => {
    try {
        const currentData = JSON.parse(event.data);
        if(currentData.type === "create") {
            createEntity(currentData.data);
        }
        if(currentData.type === "update") {
            updateEntity(currentData.data);
        }
        if(currentData.type == "delete") {
            deleteEntity(currentData.data);
        }
    } catch (e) {
        console.error("Invalid JSON:", event.data);
    }
};

socket.onclose = () => {
    console.log("Disconnected from server");
};

// --- WS DATA -------------
function createEntity(data) {
    entities.set(data.id, data);
}

function updateEntity(data) {
    console.log(data);
    const id = data.id;
    for(const key in data) {
        if(key === "id") continue;

        entities.get(id)[key] = data[key]
    }
}

function deleteEntity(data) {
    const id = data.id;
    entities.delete(id);
}


// --- Draw Shapes -------------
function transformPoint(vertex, data) {
  let x = vertex.x * data.scale.x;
  let y = vertex.y * data.scale.y;

  const rad = data.rotation;
  const cos = Math.cos(rad);
  const sin = Math.sin(rad);

  const rx = x * cos - y * sin;
  const ry = x * sin + y * cos;

  return {
    x: rx + data.position.x,
    y: ry + data.position.y
  };
}

function drawPolygon(data) {
    ctx.save()

    ctx.beginPath();

    for (let i = 0; i < data.vertices.length; i++) {
        const v = transformPoint(data.vertices[i], data);

        if (i === 0) ctx.moveTo(v.x, v.y);
        else ctx.lineTo(v.x, v.y);
    }

    ctx.closePath();

    ctx.strokeStyle = "black";
    ctx.lineWidth = 2;
    ctx.stroke();

    ctx.restore() 
}


function drawCircle(data) {
    ctx.save()

    ctx.beginPath();

    ctx.arc(
        data.position.x,
        data.position.y,
        data.radius * data.scale.x, // optional scaling
        0,
        Math.PI * 2
    );

    ctx.strokeStyle = "black";
    ctx.lineWidth = 2;
    ctx.stroke();

    ctx.restore()
}

async function render() {

    // reset transform
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // camera
    ctx.translate(canvas.width / 2, canvas.height / 2);
    ctx.scale(1, -1);


    entities.forEach(entity => {
        if (entity.shape === "polygon") {
            drawPolygon(entity);
        }
        else if(entity.shape === "circle") {
            drawCircle(entity)
        }
    })

    requestAnimationFrame(render);
}

render();
