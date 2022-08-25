using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoSerialReader : MonoBehaviour
{
    public GameObject humanDummy;

    private float analogSignal;
    void Awake()
    {
        humanDummy = GameObject.FindGameObjectWithTag("HeadBlend");
        //boxShape2 = GameObject.FindGameObjectWithTag("BlendShapedBox2");
    }

    // Invoked when a line of data is received from the serial device.
    void OnMessageArrived(string msg)
    {
        //Debug.Log(msg);

        //string[] msgSplit = msg.Split(',');
        //analogSignal = float.Parse(msgSplit[0]);
        //analogSignal2 = float.Parse(msgSplit[1]);

        analogSignal = float.Parse(msg);

        //Debug.Log("Signal 1 from Arduino: " + analogSignal);
        Debug.Log(analogSignal);

        //Debug.Log("Signal 2 from Arduino: " + analogSignal2);
        //Debug.Log(analogSignal2);
        
        //i = analogSignal;

        // Invoked when a connect/disconnect event occurs. The parameter 'success'
        // will be 'true' upon connection, and 'false' upon disconnection or
        // failure to connect.
    }
    void OnConnectionEvent(bool success)
    {
        if (success)
            Debug.Log("Connection established");
        else
            Debug.Log("Connection attempt failed or disconnection detected");
    }
    void Update() 
    {
        humanDummy.GetComponent<SkinnedMeshRenderer>().SetBlendShapeWeight(0, analogSignal);
        humanDummy.GetComponent<SkinnedMeshRenderer>().SetBlendShapeWeight(1, 30);
        humanDummy.GetComponent<SkinnedMeshRenderer>().SetBlendShapeWeight(2, 30);
        humanDummy.GetComponent<SkinnedMeshRenderer>().SetBlendShapeWeight(3, 0);
        //Debug.Log("Signal in Unity: " + i);
        //boxShape2.GetComponent<SkinnedMeshRenderer>().SetBlendShapeWeight(0, analogSignal2);
        //Debug.Log("Signal in Unity: " + i);
    }
}