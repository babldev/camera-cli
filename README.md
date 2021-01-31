# camera-cli

Tired of your webcam putting you out of focus? Turn that blurry frown upside down with `./camera-cli`!

![Before and after](img/readme.png?raw=true "Before and after")

`camera-cli` is a simple executable to configure a webcam such as the [Logitech C920 HD Pro](https://www.logitech.com/en-us/products/webcams/c920-pro-hd-webcam.960-000764.html) to specific settings.

## A script that shouldn't be necesssary, but is

For some reason, Logitech C920 [settings won't save](https://www.reddit.com/r/Twitch/comments/b5uw68/c920_settings_wont_save/) using their provided Mac [Camera Settings](https://support.logi.com/hc/en-us/articles/360024849133--Downloads-HD-Pro-Webcam-C920) app.

Running this script:
- Disables auto-focus
- Sets focus to minimum value

See [LibUVC docs](https://ken.tossell.net/libuvc/doc/) for customizing your own configuration.

Leverages [LibUVC](https://github.com/libuvc/libuvc) so likely works with [other webcams](https://en.wikipedia.org/wiki/List_of_USB_video_class_devices).

This small executable is hardly a CLI, but may become more feature-rich in the future.

## How to use

```bash
brew install libuvc
make
./camera-cli
```
 
