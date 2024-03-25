/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Homework4AudioProcessorEditor::Homework4AudioProcessorEditor (Homework4AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(0.0f, 1.0f, 0.01f);
    mGainSlider.setValue(0.5f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);

    mPitchSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mPitchSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mPitchSlider.setRange(0.0f, 5.0f, 1.0f);
    mPitchSlider.setValue(0.0f);
    mPitchSlider.addListener(this);
    addAndMakeVisible(mPitchSlider);

    mGainLabel.setText("Gain", juce::dontSendNotification);
    mGainLabel.attachToComponent(&mGainSlider, false);
    addAndMakeVisible(mGainLabel);

    mPitchLabel.setText("Pitch", juce::dontSendNotification);
    mPitchLabel.attachToComponent(&mPitchSlider, false);
    addAndMakeVisible(mPitchLabel);

    setSize(200, 300);
}

Homework4AudioProcessorEditor::~Homework4AudioProcessorEditor()
{
}

//==============================================================================
void Homework4AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void Homework4AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto leftMargin = getWidth() * 0.02;
    auto topMargin = getHeight() * 0.05;
    auto sliderHeight = getHeight() * 0.75;
    auto sliderWidth = getWidth() * 0.25;

    mGainSlider.setBounds(leftMargin, topMargin, sliderWidth, sliderHeight);
    mPitchSlider.setBounds(mGainSlider.getX() + mGainSlider.getWidth() + leftMargin, topMargin, sliderWidth, sliderHeight);
}

void Homework4AudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &mGainSlider) {
        audioProcessor.mGain = mGainSlider.getValue();
    }
    else if (slider == &mPitchSlider) {
        audioProcessor.mPitch = mPitchSlider.getValue();
    }
}