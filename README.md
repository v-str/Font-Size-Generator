<img src='https://travis-ci.org/OrdinaryMind/Font-Size-Generator.svg?branch=invention'>


# Font size generator

Small shared library for dynamic font size generation.
<br>
Status: working version is available.

<img src='https://github.com/OrdinaryMind/Font-Size-Generator/blob/master/Readme/font_size_generator.gif'>

## Description

Font size generator is a simple shared library that analyses current
widget size and compares those with default parameters. Then it perform
simple calculation and generates optimal font widget size.

For using this library just include header in your files:
**include "font_size_generator.h"**

Then declare instance of FontSizeGenerator and pass right font scale
multiplier and necessary widget.

<img src='https://github.com/OrdinaryMind/Font-Size-Generator/blob/master/Readme/FontSizeGenerator%20declaration.png'>

For font size generation you need to use GenerateFontSize method, in
resize event, for example:

<img src='https://github.com/OrdinaryMind/Font-Size-Generator/blob/master/Readme/FontSizeGenerator%20usage.png'>


