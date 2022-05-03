import {
  Typography,
  Grid,
  CssBaseline,
  Switch,
} from "@mui/material";
import React, { useState } from "react";
import { IoIosTimer } from "react-icons/io";
import {makeStopFillCall, makeFillCall, makeSpokeCall, getData} from './Movement';
import { Container, Row} from 'react-grid-system';

function Controller() {
  const [value, setValue] = useState(0.0);
  const [spoke, setSpoke] = useState(true);
  const [x_rotation, setX] = useState(0.0);
  const [y_rotation, setY] = useState(0.0);
  const [z_rotation, setZ] = useState(0.0);
  const [a_checked, set_a_checked] = useState(true);
  const [b_checked, set_b_checked] = useState(true);
  const [c_checked, set_c_checked] = useState(true);
  const [d_checked, set_d_checked] = useState(true);
  const [ab_checked, set_ab_checked] = useState(true);
  const [cd_checked, set_cd_checked] = useState(true);
  const [all_checked, set_all_checked] = useState(true);

  const aClicked=()=>{
    makeFillCall('a', a_checked);
  };

  const bClicked=()=>{
    makeFillCall('b', b_checked);
  };

  const cClicked=()=>{
    makeFillCall('c', c_checked);
  };

  const dClicked=()=>{
    makeFillCall('d', d_checked);
  };

  const abClicked=()=>{
    makeFillCall('ab', ab_checked);
  };

  const cdClicked=()=>{
    makeFillCall('cd', cd_checked);
  };

  const allClicked=()=>{
    makeFillCall('all', all_checked);
  };

  const aReleased=()=>{
    makeStopFillCall('a', a_checked);
  };

  const bReleased=()=>{
    makeStopFillCall('b', b_checked);
  };

  const cReleased=()=>{
    makeStopFillCall('c', c_checked);
  };

  const dReleased=()=>{
    makeStopFillCall('d', d_checked);
  };

  const abReleased=()=>{
    makeStopFillCall('ab', ab_checked);
  };

  const cdReleased=()=>{
    makeStopFillCall('cd', cd_checked);
  };

  const allReleased=()=>{
    makeStopFillCall('all', all_checked);
  };

  const spokeChange=()=>{
      setSpoke(!spoke);
      makeSpokeCall(spoke);
  }

  const aChange=()=>{
      set_a_checked(!a_checked);
  }
  const bChange=()=>{
      set_b_checked(!b_checked);
  }
  const cChange=()=>{
      set_c_checked(!c_checked);
  }
  const dChange=()=>{
      set_d_checked(!d_checked);
  }
  const abChange=()=>{
    set_ab_checked(!ab_checked);
  }
  const cdChange=()=>{
    set_cd_checked(!cd_checked);
  }
  const allChange=()=>{
    set_all_checked(!all_checked);
  }

  const xChange=(newValue)=>{
      setX(newValue);
  }
  const yChange=(newValue)=>{
      setY(newValue);
  }
  const zChange=(newValue)=>{
      setZ(newValue);
  }
  /** 
  setInterval(function(){
    const obj = getData().then((res) => {
      xChange(res.x.toFixed(3));
      yChange(res.y.toFixed(3));
      zChange(res.z.toFixed(3));
      setValue(res.depth.toFixed(3));
    });
  },[1000]);*/
  
  return ( <>
      <CssBaseline />
      <Grid
        sx={{
          border: "10px solid #964509",
          borderRadius: "40px",
          display: "flex",
          flexDirection: "row",
        }}
        height="90vh"
        lg={11}
        ml="8.5vh"
        mt="5vh"
        container
        p="3vh"
      >
        <Grid height="20vh" width="15vw" item>
          <Typography sx={{ fontFamily: "Orbitron" }} variant="h2">
            {value}
          </Typography>
          <Typography mt="10px" variant="h5">
            Depth
          </Typography>
          <Grid container mt="55vh" width="22vw">
            <Grid item pr="40px">
             <Switch  sx={{transform:'scale(2)'}} onChange={spokeChange}/>
             <Typography mt="10px" variant="h5">
                 Open/Close spokes
             </Typography>
            </Grid>
            <Grid>
                <IoIosTimer style={{color:"#3F9596",fontSize:"10vh"}}/>
            </Grid>
          </Grid>
        </Grid>
        <Grid>
          <Typography sx={{ fontFamily: "Orbitron" }} variant="h2">
            {x_rotation}
          </Typography>
          <Typography mt="10px" variant="h5">
            X Rotation
          </Typography>
          <Typography sx={{ fontFamily: "Orbitron" }} variant="h2">
            {y_rotation}
          </Typography>
          <Typography mt="10px" variant="h5">
            Y Rotation
          </Typography>
          <Typography sx={{ fontFamily: "Orbitron" }} variant="h2">
            {z_rotation}
          </Typography>
          <Typography mt="10px" variant="h5">
            Z Rotation
          </Typography>
        </Grid>
        <Grid>
          <Container>
            <Row>
              <input type = "checkbox" checked={a_checked} onClick={aChange}/>
              <button type="button" onMouseDown={aClicked} onMouseUp={aReleased}>Tank A</button>
              <input type = "checkbox" checked={b_checked} onClick={bChange}/>
              <button type="button" onMouseDown={bClicked} onMouseUp={bReleased}>Tank B</button>
            </Row>
            <Row>
              <input type = "checkbox" checked={c_checked} onClick={cChange}/>
              <button type="button" onMouseDown={cClicked} onMouseUp={cReleased}>Tank C</button>
              <input type = "checkbox" checked={d_checked} onClick={dChange}/>
              <button type="button" onMouseDown={dClicked} onMouseUp={dReleased}>Tank D</button>
            </Row>
          </Container>
          <Container>
            <Row>
              <input type = "checkbox" checked={ab_checked} onClick={abChange}/>
              <button type="button" onMouseDown={abClicked} onMouseUp={abReleased}>Tank A+B</button>
            </Row>
            <Row>
              <input type = "checkbox" checked={cd_checked} onClick={cdChange}/>
              <button type="button" onMouseDown={cdClicked} onMouseUp={cdReleased}>Tank C+D</button>
            </Row>
          </Container>
          <Container>
            <Row>
              <input type = "checkbox" checked={all_checked} onClick={allChange}/>
              <button type="button" onMouseDown={allClicked} onMouseUp={allReleased}>All Tanks</button>
            </Row>
          </Container>
        </Grid>
      </Grid>
    </>
  );
}

export default Controller;