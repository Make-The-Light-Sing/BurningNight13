#ifndef __EFFECT_EFFECT_H
#define __EFFECT_EFFECT_H


class Effect
{
	public :
		Effect(CRGB *leds) : leds(leds) { }
		virtual void step() {}
		virtual void after_step() {}
	protected :
		unsigned int step_index = 0;
		CRGB *leds;
};


class ColorChaseEffect : public Effect {
	public :
		ColorChaseEffect(CRGB *leds, CRGB color) : Effect(leds), color(color) { }
		void step() {
			leds[step_index] = color; // red
			step_index ++;
			if (step_index >= NUM_LEDS) {
				step_index = 0;
			}
		}
		void after_step() {
			memset(leds, 0x00, NUM_LEDS * sizeof(CRGB));
		}
	private:
		CRGB color;
};


#endif
