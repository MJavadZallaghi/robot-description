# robot-description
I'll add SDF and URDF files, their C++/python parser, and other tools for working with simulation description format of robots into this repo.

## How to use SDF parser?
1. Make the executable:
a. ```cd sdf_parser/```
b. ```mkdir build && cd build```
c. ```cmake ..```
d. ```make```

2. Parse/check your SDF:
```./check_sdf <path/to/model.sdf>```  