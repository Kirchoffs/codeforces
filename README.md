# CodeForces

## Run
On Mac:
```
>> clang++ -std=c++11 -o output/1774 1774/1774-B.cpp
>> ./output/1774
```

## C++ Notes
### Iterate the map
C++11
```
for (auto const& e: m) {
    cout << e.first << ": " << e.second << endl;
}
```