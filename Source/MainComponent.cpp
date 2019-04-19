
#include "MainComponent.h"


MainComponent::MainComponent()
{
	// Main Component
	setSize (600, 400);
	
	// Frequency Slider
	addAndMakeVisible(frequencySlider);
	frequencySlider.setRange(50, 5000);
	frequencySlider.setTextValueSuffix(" Hz");
	frequencySlider.addListener(this);
	
	// Frequency Label
	addAndMakeVisible(frequencyLabel);
	frequencyLabel.setText("Frequency", dontSendNotification);
	frequencyLabel.attachToComponent(&frequencySlider, true);
	
	// Duration Slider
	addAndMakeVisible(durationSlider);
	durationSlider.setRange(1.0 / frequencySlider.getMaximum(), 1.0 / frequencySlider.getMinimum());
	durationSlider.setTextValueSuffix(" s");
	durationSlider.addListener(this);
	
	// Duration Label
	addAndMakeVisible(durationLabel);
	durationLabel.setText("Duration", dontSendNotification);
	durationLabel.attachToComponent(&durationSlider, true);
	
	frequencySlider.setValue(500.0);
	
	frequencySlider.setSkewFactorFromMidPoint(500.0);
	durationSlider.setSkewFactorFromMidPoint(0.002);
	
	frequencySlider.setTextBoxStyle(Slider::TextBoxLeft, false, 120, frequencySlider.getTextBoxHeight());
	durationSlider.setTextBoxStyle(Slider::TextBoxLeft, false, 120, durationSlider.getTextBoxHeight());
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)

}

void MainComponent::resized()
{
	const int border = 120;
	frequencySlider.setBounds(border, 20, getWidth() - border, 20);
	durationSlider.setBounds(border, 50, getWidth() - border, 50);
}
