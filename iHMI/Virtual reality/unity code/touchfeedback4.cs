using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class touchfeedback4 : MonoBehaviour
{
    public Text ScriptTxt4;

    // Start is called before the first frame update
    void Start()
    {
        ScriptTxt4.text = "0";
    }

    // Update is called once per frame
    private void OnTriggerEnter(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt4.text = "1";
        }
    }

    private void OnTriggerExit(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt4.text = "0";
        }
    }
 
}
