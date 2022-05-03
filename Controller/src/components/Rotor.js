import { Grid, Typography,SvgIcon, Button } from '@mui/material';
import React from 'react';
import { ReactComponent as FanIcon } from '../assets/fan-solid.svg';

function Rotor(props) {
  return(
      <Grid item  width="6vw" height="20vh">
            <Typography variant="h5">
                {props.rotorName}
            </Typography>
            <Button sx={{color:'black'}}>

            <SvgIcon component={FanIcon} inheritViewBox sx={{fontSize:"80px"}} />
            </Button>
      </Grid> 
  )
}

export default Rotor;
