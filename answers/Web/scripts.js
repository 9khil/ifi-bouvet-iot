var valueElement;
var gauge;


window.onload = function(){


	  	// See https://firebase.google.com/docs/web/setup#project_setup for how to
		// auto-generate this config
		var config = {
		  apiKey: "",
		  authDomain: "",
		  databaseURL: ""
		};

		firebase.initializeApp(config);

		var rootRef = firebase.database().ref("/moistureValue");

		rootRef.on("child_added", function(snapshot) {
		  displayValue(snapshot.val());
		});


		valueElement = document.getElementById("value");

		gauge = new JustGage({
		    id: "gauge",
		    value: 0,
		    min: 0,
		    max: 510,
		    title: "Fuktighet",
		    levelColors: ["#a52a2a", "#00ff00", "#0080ff"]
		  });

		
		
	}


	function displayValue(value){

			if(value > 350){
				valueElement.innerHTML = "våt";
			}
			else if(value <= 350 && value > 150){
				valueElement.innerHTML = "fuktig";
			}else if(value <= 150){
				valueElement.innerHTML = "tørr";
			}

			updateGauge(value);
		}




	function updateGauge(value){
		
		gauge.refresh(value);
	}