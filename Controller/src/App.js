import './App.css';
import Controller from './Controller';
import {makeMovementCall, makeCancelMovementCall} from './Movement';

function movementCall(key) {
  // send api call to turn on thrusters in x direction
  if(key === 'w' || key === 'a' || key === 's' || key === 'd') {
    //console.log(key + ' is pressed');
    makeMovementCall(key);
  }
}

function cancelMovementCall(key) {
  // send api call to turn off thrusters in x direction
  if(key === 'w' || key === 'a' || key === 's' || key === 'd') {
    //console.log(key + ' is released');
    makeCancelMovementCall(key);
  }
}

function App() {
  const keymap = new Map();

  // detect for start movement
  window.addEventListener('keydown', (event) => {
    if(!keymap.has(event.key)) {
      movementCall(event.key);
      keymap.set(event.key, true);
    }
  });

  // detect for stop movement
  window.addEventListener('keyup', (event) => {
    if(keymap.has(event.key)) {
      cancelMovementCall(event.key);
      keymap.delete(event.key);
    }
  });


  return (
    <div className="App">
      <Controller/>
    </div>
  );
}

export default App;
