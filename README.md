# `vor_x6x_solar_monitoring` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)

A package műholdak napelemének teljesítményét figyeli. Amennyiben a teljesítmény 5W alá esik, egy WARN üzenetet kapunk arról,
hogy a teljesítmény túl alacsony.
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/vrsgabor/vor_x6x_solar_monitoring
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select solar_monitoring--symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r

ros2 launch solar_monitoring solar_monitoring_launch.py

```
```mermaid
graph LR;
id1([/sensor_node]):::red
id2([/monitor_node]):::red
id3[ /rand<br/>std_msgs/Float32]:::light

id1 --> id3 --> id2

classDef light fill:#34aec5,stroke:#152742,stroke-width:2px,color:#152742  
classDef dark fill:#152742,stroke:#34aec5,stroke-width:2px,color:#34aec5
classDef white fill:#ffffff,stroke:#152742,stroke-width:2px,color:#152742
classDef red fill:#ef4638,stroke:#152742,stroke-width:2px,color:#fff