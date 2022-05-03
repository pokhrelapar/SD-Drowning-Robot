//import axios from 'axios';

const axios = require("axios");
//"http://169.254.21.213:9000/"
const addr = "http://127.0.0.1:9000/"

export async function getData() {
    try {
        const response = await axios.get(addr);
        //console.log(response.data.x);
        const data = {
            'x': response.data.x,
            'y': response.data.y,
            'z': response.data.z,
            'depth': response.data.depth       
        };

        return data;
    }
    catch {
        const data = {
            'x': 0.0,
            'y': 0.0,
            'z': 0.0,
            'depth': 0.0
        };

        return data;
    }
}

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
    const response = await axios.post(addr, {
        data: {"Action":"Start","Direction":key}
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
    const response = await axios.post(addr, {
        data: {"Action":"Stop", "Direction":key}
    });
}

export function makeFillCall(tank, fill){
    console.log(`${fill ? "Filling" : "Emptying"} Tank ${tank}`);
    tellRobotToFillTank(tank, fill);
}

async function tellRobotToFillTank(tank, fill) {
    const response = await axios.post(addr, {
        data: {"Action":"Fill", "Tank":tank, "Fill":fill}
    });
}

export function makeStopFillCall(tank, fill){
    console.log(`Stop ${fill ? "Filling" : "Emptying"} Tank ${tank}`);
    tellRobotToStopFillTank(tank, fill);
}

async function tellRobotToStopFillTank(tank, fill) {
    const response = await axios.post(addr, {
        data: {"Action":"StopFill", "Tank":tank, "Fill":fill}
    });
}

export function makeSpokeCall(open) {
    console.log(`${open ? "Opening" : "Closing"} spokes`);
    tellRobotToOpenOrCloseSpokes(open);
}

async function tellRobotToOpenOrCloseSpokes(open) {
    const response = await axios.post(addr, {
        data: {"Action":"Spokes","State":open}
    });
}