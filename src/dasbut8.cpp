#include "plugin.hpp"


struct DasBut8 : Module {
	enum ParamIds {
		BUT1_PARAM,
		PATH43_1_PARAM,
		BUT3_PARAM,
		BUT4_PARAM,
		BUT5_PARAM,
		BUT6_PARAM,
		BUT7_PARAM,
		BUT8_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		OUT1_OUTPUT,
		OUT2_OUTPUT,
		OUT3_OUTPUT,
		OUT4_OUTPUT,
		OUT5_OUTPUT,
		OUT6_OUTPUT,
		OUT7_OUTPUT,
		OUT8_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		LIGHT1_LIGHT,
		LIGHT2_LIGHT,
		LIGHT3_LIGHT,
		LIGHT4_LIGHT,
		LIGHT5_LIGHT,
		LIGHT6_LIGHT,
		LIGHT7_LIGHT,
		LIGHT8_LIGHT,
		NUM_LIGHTS
	};

	DasBut8() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(BUT1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(PATH43_1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT3_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT4_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT5_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT6_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT7_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT8_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct DasBut8Widget : ModuleWidget {
	DasBut8Widget(DasBut8* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DasBut8.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(31.75, 29.482)), module, DasBut8::BUT1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(32.128, 41.577)), module, DasBut8::PATH43_1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(32.317, 54.429)), module, DasBut8::BUT3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(31.372, 66.524)), module, DasBut8::BUT4_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(31.75, 79.186)), module, DasBut8::BUT5_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(30.805, 92.226)), module, DasBut8::BUT6_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(31.183, 104.699)), module, DasBut8::BUT7_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(30.994, 116.417)), module, DasBut8::BUT8_PARAM));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.938, 27.97)), module, DasBut8::OUT1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(6.993, 39.688)), module, DasBut8::OUT2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(6.993, 49.326)), module, DasBut8::OUT3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(6.993, 59.342)), module, DasBut8::OUT4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(6.048, 71.626)), module, DasBut8::OUT5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(5.481, 86.935)), module, DasBut8::OUT6_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(5.481, 100.353)), module, DasBut8::OUT7_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(5.67, 115.472)), module, DasBut8::OUT8_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(18.71, 27.781)), module, DasBut8::LIGHT1_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(19.277, 39.121)), module, DasBut8::LIGHT2_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(18.521, 50.649)), module, DasBut8::LIGHT3_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(18.332, 63.311)), module, DasBut8::LIGHT4_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(18.71, 75.028)), module, DasBut8::LIGHT5_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(17.576, 89.391)), module, DasBut8::LIGHT6_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(18.332, 102.999)), module, DasBut8::LIGHT7_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(17.387, 115.094)), module, DasBut8::LIGHT8_LIGHT));
	}
};


Model* modelDasBut8 = createModel<DasBut8, DasBut8Widget>("DasBut8");