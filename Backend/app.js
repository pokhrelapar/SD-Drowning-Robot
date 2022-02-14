const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');

const app = express();

app.use(cors({
    origin: '*',
    methods: ['GET', 'POST']
}));

app.use(bodyParser.json());

app.post('/', function (req, res) {
    res.header("Access-Control-Allow-Origin", "*");

    switch (req.body.data.Action) {
        case "start":
            startMovement(req.body.data.Direction);
            res.send(200);
            break;
        case "stop":
            stopMovement(req.body.data.Direction);
            res.send(200);
            break;
        case "depth":
            changeDepth(req.body.data.Depth);
            res.send(200);
            break;
        case "spokes":
            changeSpokeState(req.body.data.State);
            res.send(200);
            break;
        default:
            console.log("You're trying to break something, not cool");
            res.send(400);
            break;
    }
});

app.listen(9000, () => {
    console.log('listening on port 9000');
});

function startMovement(direction) {
    console.log("Moving in " + direction);
    return;
}

function stopMovement(direction) {
    console.log("Stop moving in " + direction);
    return;
}

function changeDepth(depthLevel) {
    console.log("Changing depth to " + depthLevel);
    return;
}

function changeSpokeState(state) {
    console.log(`${state ? "Opening" : "Closing"} spokes`);
    return;
}