using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class collidearduino : MonoBehaviour
{

    SerialPort arduinodata = new SerialPort("COM3", 9600); //arduino serial port
    public string[] coll; //collide 5 finger
    public string transmissiondata; //arduino data                      
  

    private void OnCollisionEnter(Collision collision)
    {
        // On collision xcoordination controll 
        if (collision.gameObject.name == "mixamorig:LeftHandThumb3" )
        {
            coll[0] = "1";
            
        }

        if (collision.gameObject.name == "mixamorig:LeftHandIndex3")
        {
            coll[1] = "1";
           
        }

        if (collision.gameObject.name == "mixamorig:LeftHandMiddle3")
        {
            coll[2] = "1";
           
        }

        if (collision.gameObject.name == "mixamorig:LeftHandRing3")
        {
            coll[3] = "1";
            
        }

        if (collision.gameObject.name == "mixamorig:LeftHandPinky3")
        {
            coll[4] = "1";
            
        }
        transmissiondata = (coll[0] + "," + coll[1] + "," + coll[2] + "," + coll[3] + "," + coll[4]);
        arduinodata.Open();
        arduinodata.WriteLine(transmissiondata); ;
        arduinodata.Close();

    }

    private void OnCollisionExit(Collision collision)
    {
        // Exit collision x coordination controll 
        if (collision.gameObject.name == "mixamorig:LeftHandThumb3")
        {
            coll[0] = "0";
        }

        if (collision.gameObject.name == "mixamorig:LeftHandIndex3")
        {
            coll[1] = "0";
            
        }

        if (collision.gameObject.name == "mixamorig:LeftHandMiddle3")
        {
            coll[2] = "0";
            
        }

        if (collision.gameObject.name == "mixamorig:LeftHandRing3")
        {
            coll[3] = "0";
           
        }

        if (collision.gameObject.name == "mixamorig:LeftHandPinky3")
        {
            coll[4] = "0";
           
        }

        transmissiondata = (coll[0] + "," + coll[1] + "," + coll[2] + "," + coll[3] + "," + coll[4]);
        arduinodata.Open();
        arduinodata.WriteLine(transmissiondata); ;
        arduinodata.Close();
    }

      



    




}
