using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class touchfeedback5 : MonoBehaviour
{
    public Text ScriptTxt5;

    // Start is called before the first frame update
    void Start()
    {
        ScriptTxt5.text = "0";
    }

    // Update is called once per frame
    private void OnTriggerEnter(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt5.text = "1";
        }
    }

    private void OnTriggerExit(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt5.text = "0";
        }
    }
 
}
