open Rebolt;

let screenWidth = Dimensions.get(`screen)##width;

module Style = {
  open Style;
  let container =
    style([flex(1.), alignItems(Center), justifyContent(Center)]);
  let text = style([fontWeight(`_600), fontSize(Float(20.))]);
};

let component = ReasonReact.statelessComponent("SwitchFirst");

let make =
    (~navigation: NavigationConfig.SwitchNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <NavigationConfig.SwitchNavigator.Screen navigation>
      ...(
           () =>
             <View style=Style.container>
               <Text style=Style.text>
                 (ReasonReact.string("Switch first"))
               </Text>
               <TouchableOpacity
                 onPress=(
                   _e =>
                     navigation.jumpTo(NavigationConfig.Config.SwitchSecond)
                 )>
                 <Text style=Style.text>
                   (ReasonReact.string("Go to second"))
                 </Text>
               </TouchableOpacity>
             </View>
         )
    </NavigationConfig.SwitchNavigator.Screen>,
};