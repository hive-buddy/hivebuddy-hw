package be.kdg.team9.hivebuddy.controllers;

import be.kdg.team9.hivebuddy.services.ArduinoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Controller;

@Controller
public class ArduinoController implements ApplicationRunner {
    private final ArduinoService arduinoService;

    @Autowired
    public ArduinoController(ArduinoService arduinoService) {
        this.arduinoService = arduinoService;
    }

    @Override
    public void run(ApplicationArguments args) throws Exception {
        arduinoService.gatherData();
    }
}
