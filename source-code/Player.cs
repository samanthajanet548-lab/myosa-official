using UnityEngine;
using System.IO.Ports;

public class Player : MonoBehaviour
{
    private Vector3 direction;
    public float gravity = -4f;
    public float strength = 4f;
    public float tilt = 2f;

    // ---------- SERIAL ----------
    private SerialPort serial;
    public string portName = "COM3";   // Change to your Arduino COM port
    public int baudRate = 115200;

    private void Start()
    {
        direction = Vector3.zero;

        // Open serial connection only once
        if (serial == null)
        {
            serial = new SerialPort(portName, baudRate);
            serial.ReadTimeout = 20;

            try
            {
                serial.Open();
                Debug.Log("Serial connected on " + portName);
            }
            catch
            {
                Debug.LogError("Failed to open serial port");
            }
        }
    }

    private void OnEnable()
    {
        // Reset player position when enabled (e.g., after restart)
        Vector3 position = transform.position;
        position.y = 0f;
        transform.position = position;
        direction = Vector3.zero;
    }

    private void Update()
    {
        // ---------- READ SERIAL ----------
        if (serial != null && serial.IsOpen)
        {
            try
            {
                string data = serial.ReadLine().Trim();

                if (data == "JUMP")
                {
                    direction = Vector3.up * strength;
                }
            }
            catch
            {
                // Ignore timeout errors
            }
        }

        // ---------- APPLY GRAVITY ----------
        direction.y += gravity * Time.deltaTime;
        transform.position += direction * Time.deltaTime;

        // ---------- APPLY TILT ----------
        Vector3 rotation = transform.eulerAngles;
        rotation.z = direction.y * tilt;
        transform.eulerAngles = rotation;
    }

    private void OnApplicationQuit()
    {
        if (serial != null && serial.IsOpen)
        {
            serial.Close();
        }
    }

    // ---------- COLLISION HANDLING ----------
    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.tag == "Obstacle")
        {
            FindObjectOfType<GameManager>().GameOver();
        }
        else if (other.gameObject.tag == "Scoring")
        {
            FindObjectOfType<GameManager>().IncreaseScore();
        }
    }
}
