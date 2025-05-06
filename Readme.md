# GBA Gamepad tester

A rom you can use to test all the buttons in your GBA are working correctly.

Built to learn some [Butano](https://github.com/GValiente/butano)

## Development

To run this locally you need to follow the installation instructions on the [butano docs](https://gvaliente.github.io/butano/getting_started.html)

After having butano set up make sure that `LIBBUTANO, SOURCES, INCLUDES,
GRAPHICS, AUDIO and DMGAUDIO` point to your installation and that the python command is correct for your OS.

To build you can run:

```
make -j16
```

or to build on changes with fswatch:

```
fswatch -o ./** | xargs -n1 -I{} make -j16
```
