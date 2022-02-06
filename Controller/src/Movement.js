//import axios from 'axios';

const axios = require("axios");

export function makeMovementCall(key) {
    switch (key) {
        case "w":
            console.log("moving forward");
            //tellRobotToMove(key);
            break;
        case "a":
            console.log("moving left");
            //tellRobotToMove(key);
            break;
        case "s":
            console.log("moving backwards");
            //tellRobotToMove(key);
            break;
        case "d":
            console.log("moving right");
            //tellRobotToMove(key);
            break;
        default:
            break;
    }
}

async function tellRobotToMove(key) {
    const response = await axios.post("https://urlhere.com/start", {
        headers: {"Direction":key}
    });
}

export function makeCancelMovementCall(key) {
    switch (key) {
        case "w":
            console.log("stop moving forward");
            //tellRobotToStopMove(key);
            break;
        case "a":
            console.log("stop moving left");
            //tellRobotToStopMove(key);
            break;
        case "s":
            console.log("stop moving backwards");
            //tellRobotToStopMove(key);
            break;
        case "d":
            console.log("stop moving right");
            //tellRobotToStopMove(key);
            break;
        default:
            break;
    }
}

async function tellRobotToStopMove(key) {
    const response = await axios.post("https://urlhere.com/stop", {
        headers: {"Direction":key}
    });
}

export function makeDepthCall(depth) {
    console.log(`Moving to ${depth} ft deep`);
    //tellRobotToChangeDepth(depth);
}

async function tellRobotToChangeDepth(depth) {
    const response = await axios.post("https://urlhere.com/depth", {
        headers: {"Depth":depth}
    });

    console.log(response);
}

export function makeSpokeCall(open) {
    console.log(`${open ? "Opening" : "Closing"} spokes`);
    //tellRobotToOpenOrCloseSpokes(openOrClose);
}

async function tellRobotToOpenOrCloseSpokes(open) {
    const response = await axios.post("https://urlhere.com/spokes", {
        headers: {"State":open}
    });
}