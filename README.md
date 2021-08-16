# Problem-Template
Provide a description of the problem

## Status
This lab's solution is tested with Github continuous integration on 'push':

(Replace URL to the correct badge image location)

![C/C++ CI](https://github.com/ilxl-ppr/hex_color_swatch_generator/workflows/C/C++%20CI/badge.svg)

# Tag
Provide descirptive tags to easily locate the problem

# Unittest setup
cppaudit makes it easy to create unittests for your programming problem. Run the command below to pull the suggested version of cppaudit.

    git subtree add --prefix problem/tools/cppaudit https://github.com/ILXL/cppaudit main --squash

The command will copy cppaudit into the tools/cppaudit folder. Modify [tools/settings/config.mk](tools/settings/config.mk) and provide the file names used by your problem. Modify [tools/settings/unittest.cc](tools/settings/unittest.cc) and create your unit tests. Unit tests are mainly built using [Googletest](https://github.com/google/googletest), but additional macros are provided for grading specific functionalities.

# Graphics libraries
If you want to provide graphics capabilities to your problem, we highly suggest you use [cpputils](https://github.com/ILXL/cpputils) as the library was built to work with cppaudit. Run the command below to pull the suggested version of cpputils.

    git subtree add --prefix problem/cpputils https://github.com/ILXL/cpputils master --squash
