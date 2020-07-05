#include "plugin.hpp"

struct DasBut8 : Module
{
	enum ParamIds
	{
		BUT1_PARAM,
		BUT2_PARAM,
		BUT3_PARAM,
		BUT4_PARAM,
		BUT5_PARAM,
		BUT6_PARAM,
		BUT7_PARAM,
		BUT8_PARAM,
		NUM_PARAMS
	};
	enum InputIds
	{
		NUM_INPUTS
	};
	enum OutputIds
	{
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
	enum LightIds
	{
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

	DasBut8()
	{
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(BUT1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT2_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT3_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT4_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT5_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT6_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT7_PARAM, 0.f, 1.f, 0.f, "");
		configParam(BUT8_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs &args) override
	{
		lights[LIGHT1_LIGHT].setBrightness(params[BUT1_PARAM].getValue());
		lights[LIGHT2_LIGHT].setBrightness(params[BUT2_PARAM].getValue());
		lights[LIGHT3_LIGHT].setBrightness(params[BUT3_PARAM].getValue());
		lights[LIGHT4_LIGHT].setBrightness(params[BUT4_PARAM].getValue());
		lights[LIGHT5_LIGHT].setBrightness(params[BUT5_PARAM].getValue());
		lights[LIGHT6_LIGHT].setBrightness(params[BUT6_PARAM].getValue());
		lights[LIGHT7_LIGHT].setBrightness(params[BUT7_PARAM].getValue());
		lights[LIGHT8_LIGHT].setBrightness(params[BUT8_PARAM].getValue());

		outputs[OUT1_OUTPUT].setVoltage(params[BUT1_PARAM].getValue() * 10.F);
		outputs[OUT2_OUTPUT].setVoltage(params[BUT2_PARAM].getValue() * 10.F);
		outputs[OUT3_OUTPUT].setVoltage(params[BUT3_PARAM].getValue() * 10.F);
		outputs[OUT4_OUTPUT].setVoltage(params[BUT4_PARAM].getValue() * 10.F);
		outputs[OUT5_OUTPUT].setVoltage(params[BUT5_PARAM].getValue() * 10.F);
		outputs[OUT6_OUTPUT].setVoltage(params[BUT6_PARAM].getValue() * 10.F);
		outputs[OUT7_OUTPUT].setVoltage(params[BUT7_PARAM].getValue() * 10.F);
		outputs[OUT8_OUTPUT].setVoltage(params[BUT8_PARAM].getValue() * 10.F);
	}
};

struct DasButton : SvgSwitch
{
	DasButton()
	{
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/button_up.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/button_down.svg")));
	}
};

struct DasBut8Widget : ModuleWidget
{
	DasBut8Widget(DasBut8 *module)
	{
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DasBut8.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 29)), module, DasBut8::BUT1_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 41.5)), module, DasBut8::BUT2_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 54)), module, DasBut8::BUT3_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 66.5)), module, DasBut8::BUT4_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 79)), module, DasBut8::BUT5_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 91.5)), module, DasBut8::BUT6_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 104)), module, DasBut8::BUT7_PARAM));
		addParam(createParamCentered<DasButton>(mm2px(Vec(30.64, 116.4)), module, DasBut8::BUT8_PARAM));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 29)), module, DasBut8::OUT1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 41.5)), module, DasBut8::OUT2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 54)), module, DasBut8::OUT3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 66.5)), module, DasBut8::OUT4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 79)), module, DasBut8::OUT5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 91.5)), module, DasBut8::OUT6_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 104)), module, DasBut8::OUT7_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(10, 116.4)), module, DasBut8::OUT8_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 29)), module, DasBut8::LIGHT1_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 41.5)), module, DasBut8::LIGHT2_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 54)), module, DasBut8::LIGHT3_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 66.5)), module, DasBut8::LIGHT4_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 79)), module, DasBut8::LIGHT5_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 91.5)), module, DasBut8::LIGHT6_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 104)), module, DasBut8::LIGHT7_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(20.34, 116.4)), module, DasBut8::LIGHT8_LIGHT));
	}
};

Model *modelDasBut8 = createModel<DasBut8, DasBut8Widget>("DasBut8");