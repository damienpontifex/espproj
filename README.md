Download drivers from https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers

```bash
ls /dev/cu.*
```

Read from output
```bash
screen /dev/cu.SLAB_USBtoUART 115200
# ctrl-a + ctrl+\ to exit
```
