x52MFD
======

The aim of this project is to make the multi functional display (MFD) of the Saitek X52Pro useable from Flightgear.

It uses the flightgear generic protocol to retrieve the data from Flightgear and the X52MFD library from [http://plasma.hasenleithner.at/x52pro/](http://plasma.hasenleithner.at/x52pro/)
 
At this moment it is basically not much more than a proof of concept.

Features
========

- Display COM,NAV,ADR and DME frequencies on the X52Pro's MFD
- Switch between frequencies by push-scrolling the right MFD roller

Installation
===========
- download or clone the repo
- compile the code using the supplied makefile
- place the x52.xml (which is the flghtgear protocol definition) in $FG_HOME/Protocol/
- run flightgear via the supplied shell script
- run the executable x52MFD (this requires access to the joystick, so elevated privileges may be required)


License
=======
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
 
[http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)
 
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

