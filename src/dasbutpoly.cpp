#include "plugin.hpp"


struct DasButPoly : Module {
	enum ParamIds {
		BUT1_PARAM,
		BUT2_PARAM,
		BUT3_PARAM,
		BUT4_PARAM,
		BUT5_PARAM,
		BUT6_PARAM,
		BUT7_PARAM,
		BUT8_PARAM,
		BUT9_PARAM,
		BUT10_PARAM,
		BUT11_PARAM,
		BUT12_PARAM,
		BUT13_PARAM,
		BUT14_PARAM,
		BUT15_PARAM,
		BUT16_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		OUTPOLY_OUTPUT,
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
		LIGHT9_LIGHT,
		LIGHT10_LIGHT,
		LIGHT11_LIGHT,
		LIGHT12_LIGHT,
		LIGHT13_LIGHT,
		LIGHT14_LIGHT,
		LIGHT15_LIGHT,
		LIGHT16_LIGHT,
		NUM_LIGHTS
	};

	DasButPoly() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(BUT1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT3_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT4_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT5_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT6_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT7_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT8_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT9_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT10_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT11_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT12_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT13_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT14_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT15_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT16_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
		lights[LIGHT1_LIGHT].setBrightness(params[BUT1_PARAM].getValue());
		lights[LIGHT2_LIGHT].setBrightness(params[BUT2_PARAM].getValue());
		lights[LIGHT3_LIGHT].setBrightness(params[BUT3_PARAM].getValue());
		lights[LIGHT4_LIGHT].setBrightness(params[BUT4_PARAM].getValue());
		lights[LIGHT5_LIGHT].setBrightness(params[BUT5_PARAM].getValue());
		lights[LIGHT6_LIGHT].setBrightness(params[BUT6_PARAM].getValue());
		lights[LIGHT7_LIGHT].setBrightness(params[BUT7_PARAM].getValue());
		lights[LIGHT8_LIGHT].setBrightness(params[BUT8_PARAM].getValue());
		lights[LIGHT9_LIGHT].setBrightness(params[BUT9_PARAM].getValue());
		lights[LIGHT10_LIGHT].setBrightness(params[BUT10_PARAM].getValue());
		lights[LIGHT11_LIGHT].setBrightness(params[BUT11_PARAM].getValue());
		lights[LIGHT12_LIGHT].setBrightness(params[BUT12_PARAM].getValue());
		lights[LIGHT13_LIGHT].setBrightness(params[BUT13_PARAM].getValue());
		lights[LIGHT14_LIGHT].setBrightness(params[BUT14_PARAM].getValue());
		lights[LIGHT15_LIGHT].setBrightness(params[BUT15_PARAM].getValue());
		lights[LIGHT16_LIGHT].setBrightness(params[BUT16_PARAM].getValue());

		float voltages[16]{};
		for (int i = 0; i < 16; ++i)
		{
			voltages[i] = params[i].getValue() * 10.F;
		}

		//this shouldn't give me a warning while compiling but it does
		//seems to work though
		outputs[OUTPOLY_OUTPUT].setChannels(16);
		outputs[OUTPOLY_OUTPUT].writeVoltages(voltages);
	}
};

struct DasButton : SvgSwitch {
	DasButton() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/button_up.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/button_down.svg")));
	}
};

struct DasButPolyWidget : ModuleWidget {
	DasButPolyWidget(DasButPoly* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DasButPoly.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 29)), module, DasButPoly::BUT1_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 29)), module, DasButPoly::BUT2_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 41.5)), module, DasButPoly::BUT3_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 41.5)), module, DasButPoly::BUT4_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 54)), module, DasButPoly::BUT5_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 54)), module, DasButPoly::BUT6_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 66.5)), module, DasButPoly::BUT7_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 66.5)), module, DasButPoly::BUT8_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 79)), module, DasButPoly::BUT9_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 79)), module, DasButPoly::BUT10_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 91.5)), module, DasButPoly::BUT11_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 91.5)), module, DasButPoly::BUT12_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 104)), module, DasButPoly::BUT13_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 104)), module, DasButPoly::BUT14_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(10, 116.5)), module, DasButPoly::BUT15_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 116.5)), module, DasButPoly::BUT16_PARAM));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(23, 18.5)), module, DasButPoly::OUTPOLY_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 26)), module, DasButPoly::LIGHT1_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 32)), module, DasButPoly::LIGHT2_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 38.5)), module, DasButPoly::LIGHT3_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 44.5)), module, DasButPoly::LIGHT4_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 51)), module, DasButPoly::LIGHT5_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 57)), module, DasButPoly::LIGHT6_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 63.5)), module, DasButPoly::LIGHT7_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 69.5)), module, DasButPoly::LIGHT8_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 76)), module, DasButPoly::LIGHT9_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 82)), module, DasButPoly::LIGHT10_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 88.5)), module, DasButPoly::LIGHT11_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 94.5)), module, DasButPoly::LIGHT12_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 101)), module, DasButPoly::LIGHT13_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 107)), module, DasButPoly::LIGHT14_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 113.5)), module, DasButPoly::LIGHT15_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 119.5)), module, DasButPoly::LIGHT16_LIGHT));
	}
};


Model* modelDasButPoly = createModel<DasButPoly, DasButPolyWidget>("DasButPoly");