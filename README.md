# robot-description
I'll add SDF and URDF files, their C++/python parser, and other tools for working with simulation description format of robots into this repo.

## How to use SDF parser?
Make the executable:

1. ```cd sdf_parser/```
2. ```mkdir build && cd build```
3. ```cmake ..```
4. ```make```

Parse/check your SDF:

5. ```./check_sdf <path/to/model.sdf>```  