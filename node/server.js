const { spawn } = require('child_process');
const WebSocket = require('ws');
const path = require('path');

const wss = new WebSocket.Server({ port: 9001 });

console.log("WebSocket server running on ws://localhost:9001");

wss.on('connection', (ws) => {
    console.log("Client Connected");

    // Path to compiled c++ program
    const executable = (process.platform === 'win32')? 'engine.exe' : 'engine';
    const simPath = path.join(__dirname, '../cpp/build', executable)
    
    const cpp = spawn(simPath);

    // C++ -> Browser
    let buffer = ""
    cpp.stdout.on('data', (data) => {
        buffer += data.toString();

        let newlineIndex;

        while ((newlineIndex = buffer.indexOf('\n')) !== -1) {
            const line = buffer.slice(0, newlineIndex);
            buffer = buffer.slice(newlineIndex + 1);

            if (!line.trim()) continue;

            try {
                ws.send(line);
            }catch(err) {
                console.error("Bad JSON line:", line);
            }
        }

    });

    //Handle errors
    cpp.stderr.on('data', (err) => {
        console.error("C++ error:", err.toString());
    });

    // Clearnup when client disconnects
    ws.on('close', () => {
        cpp.kill();
        console.log("Client disconnected");
    });
    
});