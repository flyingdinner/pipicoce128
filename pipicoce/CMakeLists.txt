add_executable(pipicoce
        pipicoce.cpp display.cpp menudisplay/menuString.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(pipicoce pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(pipicoce)

# add url via pico_set_program_url
example_auto_set_url(pipicoce)
