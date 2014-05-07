kl-iostream
=========
A KL extension for the C++ std::iostream.

kl-iostream allows you to read and write files directly in KL. For this the C++ std::iostream is utilized.

extension status
================

This extension has been built and tested against Fabric Engine 1.11.4. Higher release might work, but this hasn't been validated. Feel free to use this code for reference or training purposes, it's meant to be an example of how to integrate custom libraries into KL.

kl-iostream currently only supports reading and writing of ascii content.

kl-iostream is not thread-safe, thus you will need to ensure to only call it from the main thread.

structure
=========

The kl-iostream extensions uses the KL2EDK tool to generate the required C++ code out of a json codegen file. This makes it easy to add functionality to the extension later, or support future versions of C++. You won't find any .cpp files in the *src* folder, the source code for certain non-automatic function bodies can be found in the .codegen.json file in the *src* folder.

The latest KL2EDK documentation can be found here: http://documentation.fabricengine.com/FabricEngine/latest/HTML/ExtensionAuthoringGuide/kl2edk.html

supported platforms
===================

To date all three major platforms (windows, linux, osx) are supported, if you build the thirdparty dependencies for the corresponding platform.

building
========

A scons (http://www.scons.org/) build script is provided. kl-iostream purely depends on C++ standard libraries.

To inform scons where to find the Fabric Engine includes as well as the thirdparty libraries, you need to set the following environment variables:

* FABRIC_EDK_DIR: Should point to Fabric Engine's EDK folder.

The temporary files will be built into the *build* folder, while the structured output files will be placed in the *stage* folder.

Note: The fabric.sh exists purely for Fabric Engine internal use.

testing
=======

The extension repository also contains a series of unit tests, with which you can validate a successful build, or simply use them for reference on how to use the extension. to launch all unit tests simply use python like this:

    python test/test_all.py

license
==========

The license used for this extensions is the new BSD license. You can find it in the root folder of the repository.
