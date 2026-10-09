from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput

class RemoteXYApp(App):
    def build(self):
        layout = BoxLayout(orientation='vertical')

        self.output_label = Label(text="Output:", size_hint_y=None, height=40)
        layout.add_widget(self.output_label)

        self.output_text = TextInput(text="", multiline=False, readonly=True)
        layout.add_widget(self.output_text)

        self.input_text = TextInput(text="", multiline=False)
        layout.add_widget(self.input_text)

        send_button = Button(text="Send", size_hint_y=None, height=40)
        send_button.bind(on_press=self.send_data)
        layout.add_widget(send_button)

        return layout

    def send_data(self, instance):
        # Implement your logic to send data here
        input_data = self.input_text.text
        # For example, print the input data
        print("Sending data:", input_data)
        # Clear the input text after sending
        self.input_text.text = ""

if __name__ == '__main__':
    RemoteXYApp().run()
