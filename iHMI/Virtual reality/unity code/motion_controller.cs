using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using UnityEngine.UI;



public class motion_controller : MonoBehaviour
{
    public float flex1;
    public float flex2;
    public float flex3;
    public float flex4;
    public float flex5;
    public float bend1;
    public float bend2;
    public float bend3;
    public float bend4;
    public float bend5;
    public float range1;
    public float range2;
    public float range3;
    public float range4;
    public float range5;
    public float raw1;
    public float raw2;
    public float raw3;
    public float raw4;
    public float raw5;
    public float v1;
    public float v2;
    public float v3;
    public float v4;
    public float v5;

    public Text text1;
    public Text text2;
    public Text text3;
    public Text text4;
    public Text text5;

    SerialPort arduinodata = new SerialPort("COM7", 9600); //arduino serial port
    public string recievingdata; //arduino data
    public string recievingdata2; //arduino data
    public string transmissiondata; //arduino data

    public string[] Rxdatas; //splited arduino data matrix
    public string[] Txdatas; //splited arduino data matrix
   
    public GameObject[] Moving; // select angle object
  


    // Start is called before the first frame update
    void Start()
    {
        arduinodata.Open();

        flex1 = 450;
        flex2 = 500;
        flex3 = 450;
        flex4 = 430;
        flex5 = 410;
        bend1 = 490;
        bend2 = 520;
        bend3 = 520;
        bend4 = 500;
        bend5 = 450;
        range1 = 0;
        range2 = 0;
        range3 = 0;
        range4 = 0;
        range5 = 0;

    }

  
    // Update is called once per frame
    void Update()
    {

        //read and split data from arduino
        recievingdata = arduinodata.ReadLine();
        string[] datas = recievingdata.Split(",");
        string state1 = text1.text;
        string state2 = text2.text;
        string state3 = text3.text;
        string state4 = text4.text;
        string state5 = text5.text;

        transmissiondata = state1 + state2 + state3 + state4 + state5;



        // 절대좌표 회전 아두이노 범위 데이터 분할 후 90도로 정규화
        raw1 = int.Parse(datas[0]);
        raw2 = int.Parse(datas[1]);
        raw3 = int.Parse(datas[2]);
        raw4 = int.Parse(datas[3]);
        raw5 = int.Parse(datas[4]);

        range1 = (bend1 - flex1);
        range2 = (bend2 - flex2);
        range3 = (bend3 - flex3);
        range4 = (bend4 - flex4);
        range5 = (bend5 - flex5);

        v1 = ((raw1 - flex1) * 60 / range1);
        v2 = ((raw2 - flex2) * 60 / range2);
        v3 = ((raw3 - flex3) * 60 / range3);
        v4 = ((raw4 - flex4) * 60 / range4);
        v5 = ((raw5 - flex5) * 60 / range5);


        //반대로 꺾임 방지
        if (v1 < 0)
        {
            v1 = 0;
        }
        if (v2 < 0)
        {
            v2 = 0;
        }
        if (v3 < 0)
        {
            v3 = 0;
        }
        if (v4 < 0)
        {
            v4 = 0;
        }
        if (v5 < 0)
        {
            v5 = 0;
        }
        //반대로 꺾임 방지
        if (v1 > 60)
        {
            v1 = 60;
        }
        if (v2 > 60)
        {
            v2 = 60;
        }
        if (v3 > 60)
        {
            v3 = 60;
        }
        if (v4 > 60)
        {
            v4 = 60;
        }
        if (v5 > 60)
        {
            v5 = 60;
        }

        // 손가락 관절 각도 반영
        Moving[0].transform.rotation = Quaternion.Euler(new Vector3(-90, 60, v1));
        Moving[1].transform.rotation = Quaternion.Euler(new Vector3(-90, 60, 2 * v1));
        Moving[2].transform.rotation = Quaternion.Euler(new Vector3(0, 0, v2 + 90));
        Moving[3].transform.rotation = Quaternion.Euler(new Vector3(0, 0, 2 * v2 + 90));
        Moving[4].transform.rotation = Quaternion.Euler(new Vector3(0, 0, v3 + 90));
        Moving[5].transform.rotation = Quaternion.Euler(new Vector3(0, 0, 2 * v3 + 90));
        Moving[6].transform.rotation = Quaternion.Euler(new Vector3(0, 0, v4 + 90));
        Moving[7].transform.rotation = Quaternion.Euler(new Vector3(0, 0, 2 * v4 + 90));
        Moving[8].transform.rotation = Quaternion.Euler(new Vector3(0, 0, v5 + 90));
        Moving[9].transform.rotation = Quaternion.Euler(new Vector3(0, 0, 2 * v5 + 90));
        
        
        
        arduinodata.Write(transmissiondata);
        
    }
        
        
}