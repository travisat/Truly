#include "plugin.hpp"


struct DasBut : Module {
	enum ParamIds {
		BUT1_PARAM,
		BUT2_PARAM,
		BUT3_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		OUT3_OUTPUT,
		OUT2_OUTPUT,
		OUT1_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		LIGHT1_LIGHT,
		LIGHT2_LIGHT,
		LIGHT3_LIGHT,
		NUM_LIGHTS
	};

	DasBut() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(BUT1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT3_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
		outputs[OUT1_OUTPUT].setVoltage(params[BUT1_PARAM].getValue() * 10.F);
		lights[LIGHT1_LIGHT].setBrightness(params[BUT1_PARAM].getValue());
		outputs[OUT2_OUTPUT].setVoltage(params[BUT2_PARAM].getValue() * 10.F);
		lights[LIGHT2_LIGHT].setBrightness(params[BUT2_PARAM].getValue());
		outputs[OUT3_OUTPUT].setVoltage(params[BUT3_PARAM].getValue() * 10.F);
		lights[LIGHT3_LIGHT].setBrightness(params[BUT3_PARAM].getValue());
	}
};

struct DasButton : SvgSwitch {
	DasButton() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/button_up.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/button_down.svg")));
	}
};


struct DasButWidget : ModuleWidget {
	DasButWidget(DasBut* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DasBut.svg")));

		//addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		//addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<DasButton>(mm2px(Vec(10.16, 46)), module, DasBut::BUT1_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10.16, 78)), module, DasBut::BUT2_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10.16, 110)), module, DasBut::BUT3_PARAM));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10.16, 30)), module, DasBut::OUT1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10.16, 62)), module, DasBut::OUT2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10.16, 94)), module, DasBut::OUT3_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(10.16, 37)), module, DasBut::LIGHT1_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(10.16, 69)), module, DasBut::LIGHT2_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(10.16, 101)), module, DasBut::LIGHT3_LIGHT));
	}
};


Model* modelDasBut = createModel<DasBut, DasButWidget>("DasBut");