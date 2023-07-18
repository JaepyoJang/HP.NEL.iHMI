using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class touchfeedback1 : MonoBehaviour
{
    public Text ScriptTxt1;

    // Start is called before the first frame update
    void Start()
    {
        ScriptTxt1.text = "0";
    }

    // Update is called once per frame
    private void OnTriggerEnter(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt1.text = "1";
        }
    }

    private void OnTriggerExit(Collider collision)
    {
        // On collision controll 
        if (collision.gameObject.name == "Sphere")
        {

            ScriptTxt1.text = "0";
        }
    }
 
}
