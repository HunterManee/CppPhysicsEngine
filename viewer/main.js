const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");


async function loadData() {
    const response = await fetch("../data.json");
    return await response.json();
}

function transformPoint(p, t) {
  let x = p.x * t.scale.x;
  let y = p.y * t.scale.y;

  const rad = t.rotation;
  const cos = Math.cos(rad);
  const sin = Math.sin(rad);

  const rx = x * cos - y * sin;
  const ry = x * sin + y * cos;

  return {
    x: rx + t.position.x,
    y: ry + t.position.y
  };
}

function drawPolygon(vertices, transform) {
    ctx.beginPath();

    for (let i = 0; i < vertices.length; i++) {
        const v = transformPoint(vertices[i], transform);

        if (i === 0) ctx.moveTo(v.x, v.y);
        else ctx.lineTo(v.x, v.y);
    }

    ctx.closePath();

    ctx.strokeStyle = "black";
    ctx.lineWidth = 2;
    ctx.stroke();
}

async function main() {
    const data = await loadData();

    console.log(data);

    // reset transform
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // camera
    ctx.translate(canvas.width / 2, canvas.height / 2);
    ctx.scale(1, -1);

    if (data.collider.type === "polygon") {
        drawPolygon(data.collider.vertices, data.transform);
    }
}

main();