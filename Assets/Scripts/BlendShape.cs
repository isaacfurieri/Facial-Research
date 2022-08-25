using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlendShape : MonoBehaviour
{
    private const float V = 0.01f;
    public GameObject boxShape;
    SkinnedMeshRenderer skinnedMeshRenderer;
    Mesh skinnedMesh;
    float i = 0.0f;
    // Start is called before the first frame update
    void Start()
    {
         boxShape = GameObject.FindGameObjectWithTag("BlendShapedBox");
    }

    // Update is called once per frame
    void Update()
    {
        if(i < 100.0)
        {
            boxShape.GetComponent<SkinnedMeshRenderer>().SetBlendShapeWeight(0, i);
            i = i + V;
        }
    }
}
