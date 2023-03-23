import { Component, OnInit } from '@angular/core';
import { Route, Router } from '@angular/router';
import { ItemListService } from '../item-list.service';


@Component({
  selector: 'app-update',
  templateUrl: './update.component.html',
  styleUrls: ['./update.component.css']
})
export class UpdateComponent implements OnInit {
    
  constructor(private itemservice: ItemListService, private route: Router) { }
  
  fetched_items = this.itemservice.getItemToBeSelected();
  
  ngOnInit(): void {
    throw new Error('Method not implemented.');
  }

  saveUpdate(): void {
    this.route.navigate(['home']);
  }

}
