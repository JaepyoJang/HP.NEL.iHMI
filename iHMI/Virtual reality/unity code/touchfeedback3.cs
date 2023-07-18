using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class touchfeedback3 : MonoBehaviour
{
    public Text ScriptTxt3;

    // Start is called before the first frame update
    void Start()
    {
        ScriptTxt3.text = "0";
    }

    // Update is called once per frame
    private void OnTriggerEnter(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt3.text = "1";
        }
    }

    private void OnTriggerExit(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt3.text = "0";
        }
    }
 
}
