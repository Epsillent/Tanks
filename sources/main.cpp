#include "engine.hpp"
#include "components/particle_system.hpp"
#include "scenes/battlefield.hpp"

int main(){
    Engine *engine = new Engine;
    EngineProperties props;
    props.frame_rate_limit = 60;
    props.window_title = "Tanks";
    props.window_width = 1280;
    props.window_heigth = 720;
    engine->init(props);
    engine->set_entry_scene(new Battlefield, "Battlefield");
    engine->start();
}
