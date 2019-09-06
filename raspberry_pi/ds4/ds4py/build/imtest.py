import ds4py, time

running = True

ds = ds4py.DS4_util()
ds.DS4_init("/dev/input/js0")



if __name__ == "__main__":
    print(ds.DS4_GetDeviceName())
    try:
        while True:
            print(ds.DS4_GetAxis(3), ds.DS4_GetButton(2))
            time.sleep(0.01)

    finally:
        del ds
