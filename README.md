# camera-cli

Tired of your webcam putting you out of focus after it forgets your preferred settings?

Turn that blurry frown upside down with `./camera-cli`

![Before and after](img/readme.png?raw=true "Before and after")

`camera-cli` is a tiny executable for quickly configuring a webcam such as the [Logitech C920 HD Pro](https://www.logitech.com/en-us/products/webcams/c920-pro-hd-webcam.960-000764.html) to specific settings.

## A forgetful camera
The [Logitech C920 (and perhaps many other webcams) reset settings every time they are unplugged](https://www.reddit.com/r/obs/comments/fflg5g/logitech_cam_keeps_resetting_video_settings_back//). For those who use a laptop / frequently disconnect a camera, this can be extremely annoying. The [Camera Settings app provided by Logitech](https://support.logi.com/hc/en-us/articles/360024849133--Downloads-HD-Pro-Webcam-C920) requires a bunch of steps to reapply preferred settings. I built this script as a faster alternative to the Logitech app.

The script currently:
- Disables auto-focus
- Sets focus to minimum value

See [LibUVC docs](https://ken.tossell.net/libuvc/doc/) for customizing your own configuration.

Leverages [LibUVC](https://github.com/libuvc/libuvc) so likely works with [other webcams](https://en.wikipedia.org/wiki/List_of_USB_video_class_devices).

This small executable is hardly a CLI, but may become more customizable and easy to install in the future if there is demand.

## How to use
Requires [homebrew](https://brew.sh/)

On Mac: (Intel or Apple Silicon)
```bash
brew install libuvc
make
./camera-cli
```
