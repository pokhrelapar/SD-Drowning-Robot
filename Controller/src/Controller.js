import {
  Typography,
  Grid,
  CssBaseline,
  Slider,
  Box,
  Button,
  Switch,
} from "@mui/material";
import React, { useState } from "react";
import Rotor from "./components/Rotor";
import CircleIcon from "@mui/icons-material/Circle";
import { IoIosTimer } from "react-icons/io";

function Controller() {
  const [value, setValue] = useState(0.0);
  const [spoke, setSpoke] = useState(true);

  const handleChange = (event, newValue) => {
    if (typeof newValue === "number") {
      setValue(newValue);
    }
  };

  const spokeChange=()=>{
      setSpoke(!spoke);
      if(spoke){
          console.log("Spoke open")
      }
      else{
          console.log("Spoke close")
      }
  }
  return (
    <>
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
        <Grid item>
          <Box
            mr="20px"
            height="40vh"
            width="70vh"
            display="flex"
            justifyContent="center"
            alignItems="center"
            sx={{ border: "4px solid black" }}
          >
            <Typography sx={{ fontSize: "3vh" }} variant="overline">
              Video Feed
            </Typography>
          </Box>
        </Grid>
        <Grid mr="20px" item>
          <Slider
            value={value}
            min={0.0}
            step={0.99}
            orientation="vertical"
            max={100}
            onChange={handleChange}
            valueLabelDisplay="auto"
            aria-labelledby="non-linear-slider"
          />
        </Grid>
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
        <Grid ml="6vw" container width="26vw" height="70vh">
          <Grid item xs={12} align="center">
            <Rotor rotorName="T1" />
          </Grid>
          <Grid item xs={4} align="center">
            <Rotor rotorName="T2" />
          </Grid>
          <Grid item xs={4} m="auto">
            <Button>
              <CircleIcon sx={{ color: "red", fontSize: "80px" }} />
            </Button>
          </Grid>
          <Grid item xs={4} align="center">
            <Rotor rotorName="T3" />
          </Grid>
          <Grid item xs={12} align="center">
            <Rotor rotorName="T4" />
          </Grid>
          <Grid item xs={12} align="center">
            <Typography variant="h4">Thruster Controls</Typography>
          </Grid>
        </Grid>
         
      </Grid>
    </>
  );
}

export default Controller;
