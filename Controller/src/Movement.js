//import axios from 'axios';

const axios = require("axios");

export function makeMovementCall(key) {
    switch (key) {
        case "w":
            console.log("moving forward");
            tellRobotToMove(key);
            break;
        case "a":
            console.log("moving left");
            tellRobotToMove(key);
            break;
        case "s":
            console.log("moving backwards");
            tellRobotToMove(key);
            break;
        case "d":
            console.log("moving right");
            tellRobotToMove(key);
            break;
        default:
            break;
    }
}

async function tellRobotToMove(key) {
    const response = await axios.post("http://localhost:9000/", {
        data: {"Action":"start","Direction":key}
    });
}

export function makeCancelMovementCall(key) {
    switch (key) {
        case "w":
            console.log("stop moving forward");
            tellRobotToStopMove(key);
            break;
        case "a":
            console.log("stop moving left");
            tellRobotToStopMove(key);
            break;
        case "s":
            console.log("stop moving backwards");
            tellRobotToStopMove(key);
            break;
        case "d":
            console.log("stop moving right");
            tellRobotToStopMove(key);
            break;
        default:
            break;
    }
}

async function tellRobotToStopMove(key) {
    const response = await axios.post("http://localhost:9000/", {
        data: {"Action":"stop", "Direction":key}
    });
}

export function makeDepthCall(depth) {
    console.log(`Moving to ${depth} ft deep`);
    tellRobotToChangeDepth(depth);
}

async function tellRobotToChangeDepth(depth) {
    const response = await axios.post("http://localhost:9000/", {
        data: {"Action":"depth", "Depth":depth}
    });

    console.log(response);
}

export function makeSpokeCall(open) {
    console.log(`${open ? "Opening" : "Closing"} spokes`);
    tellRobotToOpenOrCloseSpokes(open);
}

async function tellRobotToOpenOrCloseSpokes(open) {
    const response = await axios.post("http://localhost:9000/", {
        data: {"Action":"spokes","State":open}
    });
}